package secondLab;

import firstLab.*;
import logs.Logger;
import org.apache.commons.math3.linear.MatrixUtils;
import org.apache.commons.math3.linear.RealVector;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.function.Function;

public class TestRunner {
    static double eps = 1E-4;
    static Random rand = new Random();

    static Logger logger = new Logger("Table.xls");

    static ArrayList<ArrayList<DiagonalQuadraticFunction>> array = new ArrayList<>();

    static int[] K = {1, 10, 100, 200, 300, 500, 700, 1000};
    static int[] N = {10, 100, 500, 1000, 3000, 5000, 10000};

    public static void main(String[] args) {
        init();

        run(s -> new GradientDescent(s, eps), "GradientDescent");

        run(s -> new ConjugateGradient(s, eps), "ConjugateGradient");


        run(s -> new SteepestDescent(s, eps, new Dichotomy()), "SteepestDescent_Dichotomy");

        run(s -> new SteepestDescent(s, eps, new Fibonacci()), "SteepestDescent_Fibonacci");

        run(s -> new SteepestDescent(s, eps, new GoldenSection()), "SteepestDescent_GoldenSection");

//        run(s -> new SteepestDescent(s, eps, new Parabolas()), "SteepestDescent_Parabolas");

        run(s -> new SteepestDescent(s, eps, new Brent()), "SteepestDescent_Brent");
    }

    public static void init() {
        for (int i = 0; i < N.length; ++i) {
            array.add(new ArrayList<>());
            for (int k : K) {
                array.get(i).add(new DiagonalQuadraticFunction(generate(N[i], k), generate(N[i]), rand.nextDouble()));
            }
        }
    }

    public static RealVector generate(int n) {
        double[] res = new double[n];
        for (int i = 0; i < n; i++) {
            res[i] = rand.nextDouble();
        }
        return MatrixUtils.createRealVector(res);
    }

    public static RealVector generate(int n, int k) {
        double[] res = new double[n];
        res[0] = Math.abs(rand.nextDouble());
        res[1] = res[0] * k;

        for (int i = 2; i < n; i++) {
            res[i] = Math.max(Math.abs(rand.nextDouble()) % res[1], res[0]);
        }
        return MatrixUtils.createRealVector(res);
    }

    public static void run(Function<QuadrFunction, AbstractSolver> constructor, String name) {
        System.out.println(name);
        logger.addOrGetSheet(name, false);
        logger.write("N\\K");
        for (int k : K) {
            logger.write(k);
        }
        logger.nextLine();
        List<AbstractSolver> solvers = new ArrayList<>();
        for (int i = 0; i < N.length; ++i) {
            for (int j = 0; j < K.length; ++j) {
                solvers.add(constructor.apply(array.get(i).get(j)));
            }
        }

        solvers.parallelStream().forEach(AbstractSolver::findMin);


        for (int i = 0; i < N.length; ++i) {
            int n = N[i];
            logger.write(n);
            for (int j = 0; j < K.length; ++j) {
                AbstractSolver solver = solvers.get(i * K.length + j);
                long iter = solver.getIterations();
                if (iter > 100_000) {
                    logger.write("!>100_000");
                } else {
                    logger.write(iter);
                }
            }
            logger.nextLine();
        }
        try {
            logger.writeInFile();
        } catch (IOException ignored) {
        }
        System.out.println("Done\n");
    }
}
