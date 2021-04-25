package secondLab;


import firstLab.Optimizer;
import org.apache.commons.math3.linear.MatrixUtils;

import java.lang.reflect.InvocationTargetException;
import java.util.Arrays;


public class Main {
    static double eps = 1E-5;
    static QuadrFunction func1 = new QuadraticFunction(
            MatrixUtils.createRealMatrix(new double[][]{{2, 2}, {2, 4}}),
            MatrixUtils.createRealVector(new double[]{2, 4}),
            3);

    static QuadrFunction func = new QuadraticFunction(
            MatrixUtils.createRealMatrix(new double[][]{{144., -120.}, {-120., 144.}}),
            MatrixUtils.createRealVector(new double[]{12., -30.}),
            25.);

    public static void main(String[] args) {
        System.out.println("GradientDescent\n");
        GradientDescent gradientDescent = new GradientDescent(func, eps);
        Pair answer = gradientDescent.findMin();
        Arrays.stream(answer.getValue().toArray()).forEach(s -> System.out.print(s + " "));
        System.out.println("\n" + answer.getFuncValue());
        System.out.println("Iterations: " + gradientDescent.resetIterations() + "\n-------------------------\n");

        System.out.println("ConjugateGradient\n");
        ConjugateGradient conjGrad = new ConjugateGradient(func, eps);
        answer = conjGrad.findMin();
        Arrays.stream(answer.getValue().toArray()).forEach(s -> System.out.print(s + " "));
        System.out.println("\n" + answer.getFuncValue());
        System.out.println("Iterations: " + conjGrad.resetIterations() + "\n-------------------------\n");


        runSteepestDescent("firstLab.Dichotomy");
        runSteepestDescent("firstLab.Fibonacci");
        runSteepestDescent("firstLab.GoldenSection");
        runSteepestDescent("firstLab.Parabolas");
        runSteepestDescent("firstLab.Brent");
    }

    static void runSteepestDescent(String name) {
        System.out.println(name + "\n");
        SteepestDescent steepestDescent;
        try {
            steepestDescent = new SteepestDescent(func, eps, (Optimizer) Class.forName(name).getDeclaredConstructor().newInstance());
        } catch (ClassNotFoundException | InstantiationException |
                IllegalAccessException | NoSuchMethodException | InvocationTargetException ignored) {
            System.err.println("((");
            return;
        }
        Pair answer = steepestDescent.findMin();
        Arrays.stream(answer.getValue().toArray()).forEach(s -> System.out.print(s + " "));
        System.out.println("\n" + answer.getFuncValue());
        System.out.println("Iterations: " +
                steepestDescent.getIterations() + " || All Iterations: " +
                steepestDescent.resetIterations() + "\n-------------------------\n");
    }
}
