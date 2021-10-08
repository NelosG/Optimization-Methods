package secondLab;

import firstLab.Brent;
import firstLab.Dichotomy;
import firstLab.Fibonacci;
import firstLab.GoldenSection;
import logs.Logger;
import org.apache.commons.math3.linear.MatrixUtils;
import org.apache.commons.math3.linear.RealVector;

import java.io.IOException;
import java.util.*;
import java.util.function.Function;

public class TestRunner {
    static double eps = 1E-4;
    static Random rand = new Random();

    static Logger logger = new Logger("Table.xls");

    static ArrayList<ArrayList<DiagonalQuadraticFunction>> array = new ArrayList<>();
    static ArrayList<ArrayList<ArrayList<Double>>> answers = new ArrayList<>();
    static ArrayList<ArrayList<ArrayList<ArrayList<Long>>>> count = new ArrayList<>();

    static int[] K = {1, 10, 100, 200, 300, 500, 700, 1000, 2000};
    static int[] N = {10, 100, 500, 1000, 3000, 5000, 10000};

    public static void main(String[] args) {
        initCount();
        int runCount = 5;
        for (int i = 0; i < runCount; i++) {
            init();
            int j = 0;
            run(s -> new GradientDescent(s, eps), "GradientDescent", j++, i);

            run(s -> new ConjugateGradient(s, eps), "ConjugateGradient", j++, i);


            run(s -> new SteepestDescent(s, eps, new Dichotomy()), "SteepestDescent_Dichotomy", j++, i);

            run(s -> new SteepestDescent(s, eps, new Fibonacci()), "SteepestDescent_Fibonacci", j++, i);

            run(s -> new SteepestDescent(s, eps, new GoldenSection()), "SteepestDescent_GoldenSection", j++, i);

//        run(s -> new SteepestDescent(s, eps, new Parabolas()), "SteepestDescent_Parabolas", 0);
//
            run(s -> new SteepestDescent(s, eps, new Brent()), "SteepestDescent_Brent", j++, i);
        }

        int j = 0;
        print("GradientDescent", j++);

        print("ConjugateGradient", j++);


        print("SteepestDescent_Dichotomy", j++);

        print("SteepestDescent_Fibonacci", j++);

        print("SteepestDescent_GoldenSection", j++);

//        run(s -> new SteepestDescent(s, eps, new Parabolas()), "SteepestDescent_Parabolas", 0);
//
        print("SteepestDescent_Brent", j++);
//        printAnswers();
    }

    private static void print(String name, int numb){
        logger.addOrGetSheet(name, false);
        logger.write("N\\K");
        for (int k : K) {
            logger.write(k);
        }
        logger.nextLine();
        for (int i = 0; i < N.length; ++i) {
            int n = N[i];
            logger.write(n);
            for (int j = 0; j < K.length; ++j) {
                logger.write(find(count.get(numb).get(i).get(j)));
            }
            logger.nextLine();
        }
        try {
            logger.writeInFile();
        } catch (IOException ignored) {
        }
    }

    private static Long find(ArrayList<Long> arr){
        Set<Integer> set = new HashSet<>();

        Collections.sort(arr, new Comparator<Long>() {
            public int compare(Long o1, Long o2) {
                return o2.compareTo(o1);
            }
        });
        int c = arr.size();
        Long sum = 0L;
        Long sumAll = 0L;

        System.out.println("--------------------------------");
        for(Long l : arr) {
            sum += l;
            System.out.print(l + " ");
        }
        sumAll = sum;
        System.out.println();
        boolean flag = true;
        while(flag) {
            flag = false;
            for(int i = 0; i < arr.size(); i++) {
                if(!set.contains(i)) {
                    boolean flag1 = false;
                    for(int j = 0; j < arr.size(); j++) {
                        if(!set.contains(j)) {
                            if(arr.get(i) > arr.get(j) * 2 || arr.get(i) < arr.get(j) /2) {
                                flag1 = true;
                                break;
                            }
                        }
                    }
                    if(flag1) {
                        System.out.println("added " + i);
                        set.add(i);
                        sum -= arr.get(i);
                        c--;
                        flag = true;
                    }
                }
            }
        }
        System.out.println("--------------------------------");
        return (sum + sumAll)/2 / c;
    }

    private static void initCount() {
        for (int i = 0; i < 6; i++) {
            count.add(new ArrayList<>());
            for (int j = 0; j < N.length; ++j) {
                count.get(i).add(new ArrayList<>());
                for (int k = 0; k < K.length; ++k) {
                    count.get(i).get(j).add(new ArrayList<>());
                }
            }
        }
    }

    public static void init() {
        array = new ArrayList<>();
        answers = new ArrayList<>();
        for (int i = 0; i < N.length; ++i) {
            array.add(new ArrayList<>());
            answers.add(new ArrayList<>());
            for (int k : K) {
                answers.get(i).add(new ArrayList<>(Collections.nCopies(6, null)));
                array.get(i).add(new DiagonalQuadraticFunction(generate(N[i], k), generate(N[i]), rand.nextDouble()));
            }
        }
    }

    public static void printAnswers() {
        logger.addOrGetSheet("Answer_Statistic", false);
        logger.writeln("N", "K", "GradientDescent", "ConjugateGradient", "Dichotomy",
                "Fibonacci", "GoldenSection", /*"Parabolas",*/ "Brent", "Average", "Difference");

        for (int i = 0; i < N.length; ++i) {
            logger.writeln(N[i]);
            for (int j = 0; j < K.length; ++j) {
                logger.write("", K[j]);
                double aw = 0;
                double max = Integer.MIN_VALUE;
                double min = Integer.MAX_VALUE;
                for (Double d : answers.get(i).get(j)) {
                    logger.write(d);
                    aw += d;
                    if (d > max) {
                        max = d;
                    }
                    if (d < min) {
                        min = d;
                    }
                }
                logger.writeln(aw / answers.get(i).get(j).size(), max - min);
                if (max - min > 2 * eps) {
                    System.err.println("Grustna  " + (max - min));
                }
            }
            logger.nextLine();
        }
        try {
            logger.writeInFile();
        } catch (IOException e) {
            e.printStackTrace();
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

    public static void run(Function<QuadrFunction, AbstractSolver> constructor, String name, int numb, int runN) {
        System.out.println(name);
//        logger.addOrGetSheet(name, false);
//        logger.write("N\\K");
//        for (int k : K) {
//            logger.write(k);
//        }
//        logger.nextLine();
        List<AbstractSolver> solvers = new ArrayList<>();
        List<Thread> threads = new ArrayList<>();
        for (int i = 0; i < N.length; ++i) {
            for (int j = 0; j < K.length; ++j) {
                AbstractSolver solver = constructor.apply(array.get(i).get(j));
                solvers.add(solver);
                int finalI = i;
                int finalJ = j;
                Thread thread = new Thread(() -> answers.get(finalI).get(finalJ).set(numb, solver.findMin().getFuncValue()));
                threads.add(thread);
                thread.start();
            }
        }
        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException ignored) {

            }
        }

        for (int i = 0; i < N.length; ++i) {
            int n = N[i];
//            logger.write(n);
            for (int j = 0; j < K.length; ++j) {
                AbstractSolver solver = solvers.get(i * K.length + j);
                long iter = solver.resetIterations();
                count.get(numb).get(i).get(j).add(iter);
//                logger.write(iter);
            }
//            logger.nextLine();
        }
//        try {
//            logger.writeInFile();
//        } catch (IOException ignored) {
//        }
        System.out.println("Done\n");
    }
}
