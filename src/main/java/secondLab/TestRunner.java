package secondLab;

import firstLab.*;
import logs.Logger;
import org.apache.commons.math3.linear.MatrixUtils;
import org.apache.commons.math3.linear.RealVector;


import java.io.IOException;
import java.util.Random;
import java.util.function.Function;

public class TestRunner {
    static double eps = 1E-3;
    static Random rand = new Random();

    static Logger logger = new Logger("./table.xls");

    public static void main(String[] args) {
        run(s -> new GradientDescent(s, eps), "GradientDescent");

        run(s -> new ConjugateGradient(s, eps), "ConjugateGradient");


        run(s -> new SteepestDescent(s, eps, new Dichotomy()), "SteepestDescent_Dichotomy");

        run(s -> new SteepestDescent(s, eps, new Fibonacci()), "SteepestDescent_Fibonacci");

        run(s -> new SteepestDescent(s, eps, new GoldenSection()), "SteepestDescent_GoldenSection");
//
//        run(s -> new SteepestDescent(s, eps, new Parabolas()), "SteepestDescent_Parabolas");
//
        run(s -> new SteepestDescent(s, eps, new Brent()), "SteepestDescent_Brent");
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
        int[] K = {1, 10, 100, 200, 300, 500, 700, 1000};
        int[] N = {10, 100, 500, 1000, 3000, 10000};

        logger.addOrGetSheet(name, false);
        logger.write("N\\K");
        for (int k : K) {
            logger.write(k);
            if(k == 10) {
                k = 0;
            }
        }
        logger.nextLine();
        for (int n : N) {
            System.out.println(name + " : " + n);
            logger.write(n);
            for (int k : K) {
                AbstractSolver solver = constructor.apply(new DiagonalQuadraticFunction(generate(n, k), generate(n), rand.nextDouble()));
                solver.findMin();
                long iter = solver.getIterations();
                if(iter > 100_000) {
                    logger.write("!>100_000");
                } else {
                    logger.write(iter);
                }
                solver.resetIterations();
            }
            logger.nextLine();
        }
        try {
            logger.writeInFile();
        } catch (IOException ignored) {
        }
    }
}
