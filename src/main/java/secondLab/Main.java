package secondLab;


import firstLab.*;
import org.apache.commons.math3.linear.MatrixUtils;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;

import java.util.Arrays;


public class Main {
    static double eps = 1e-6;
    public static void main(String[] args) {

        RealMatrix a = MatrixUtils.createRealMatrix(new double[][]{{2, 2}, {2, 4}});
        RealVector b = MatrixUtils.createRealVector(new double[]{2, 4});
        double c = 3;

        System.out.println("GradientDescent\n");
        GradientDescent gradientDescent = new GradientDescent(new QuadraticFunction(a, b, c), eps);
        Pair answer = gradientDescent.findMin();
        Arrays.stream(answer.getValue().toArray()).forEach(s -> System.out.print(s + " "));
        System.out.println("\n" + answer.getFuncValue());
        System.out.println("Iterations: " + gradientDescent.resetIterations() + "\n-------------------------\n");


        System.out.println("ConjugateGradient\n");
        ConjugateGradient conjGrad = new ConjugateGradient(new QuadraticFunction(a, b, c), eps);
        answer = conjGrad.findMin();
        Arrays.stream(answer.getValue().toArray()).forEach(s -> System.out.print(s + " "));
        System.out.println("\n" + answer.getFuncValue());
        System.out.println("Iterations: " + conjGrad.resetIterations() + "\n-------------------------\n");


        runSteepestDescent("firstLab.Dichotomy", a, b, c);
//        runSteepestDescent("firstLab.Fibonacci", a, b, c);
        runSteepestDescent("firstLab.GoldenSection", a, b, c);
        runSteepestDescent("firstLab.Parabolas", a, b, c);
        runSteepestDescent("firstLab.Brent", a, b, c);
    }

    static void runSteepestDescent(String name, RealMatrix a, RealVector b, double c) {
        System.out.println(name + "\n");
        SteepestDescent steepestDescent;
        try {
            steepestDescent = new SteepestDescent(new QuadraticFunction(a, b, c), eps, (Optimizer) Class.forName(name).newInstance());
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException ignored) {
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
