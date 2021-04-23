package secondLab;


import firstLab.*;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    static double eps = 1e-6;
    static List<Long> iter = new ArrayList<>();
    public static void main(String[] args) {
        List<Vector> A = new ArrayList<>(Collections.nCopies(2, new Vector()));
        Vector tmp = new Vector();
        tmp.add(2.);
        tmp.add(2.);
        A.set(0, tmp);
        tmp = new Vector();
        tmp.add(2.);
        tmp.add(4.);
        A.set(1, tmp);
        Vector B = new Vector();
        B.add(2.);
        B.add(4.);


        Matrix a = new Matrix(A);
        Vector b = new Vector(B);
        double c = 3;

        System.out.println("GradientDescent\n");
        GradientDescent gradientDescent = new GradientDescent(new QuadraticFunction(a, b, c), eps);
        Pair answer = gradientDescent.findMin();
        answer.getValue().getCoefficients().forEach(s -> System.out.print(s + " "));
        System.out.println("\n" + answer.getFuncValue() + "\n");
        iter.add(gradientDescent.resetIterations());


        System.out.println("ConjugateGradient\n");
        ConjugateGradient conjGrad = new ConjugateGradient(new QuadraticFunction(a, b, c), eps);
        answer = conjGrad.findMin();
        answer.getValue().getCoefficients().forEach(s -> System.out.print(s + " "));
        System.out.println("\n" + answer.getFuncValue() + "\n");
        iter.add(conjGrad.resetIterations());


        runSteepestDescent("firstLab.Dichotomy", a, b, c);
//        runSteepestDescent("firstLab.Fibonacci", a, b, c);
        runSteepestDescent("firstLab.GoldenSection", a, b, c);
        runSteepestDescent("firstLab.Parabolas", a, b, c);
        runSteepestDescent("firstLab.Brent", a, b, c);
        System.out.println("\n\n!!_-_-_-_-_-_-_-_-_-_-_-_-!!\n\n");

        iter.forEach(System.out::println);
    }

    static void runSteepestDescent(String name, Matrix a, Vector b, double c) {
        System.out.println(name + "\n");
        SteepestDescent steepestDescent;
        try {
            steepestDescent = new SteepestDescent(new QuadraticFunction(a, b, c), eps, (Optimizer) Class.forName(name).newInstance());
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException ignored) {
            System.err.println("((");
            return;
        }
        Pair answer = steepestDescent.findMin();
        answer.getValue().getCoefficients().forEach(s -> System.out.print(s + " "));
        System.out.println("\n" + answer.getFuncValue() + "\n");
        iter.add(steepestDescent.resetIterations());
    }
}
