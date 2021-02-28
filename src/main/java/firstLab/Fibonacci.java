package firstLab;

import java.util.function.Function;

public class Fibonacci implements Optimizer {


    @Override
    public double optimize(double leftBound, double rightBound, double eps, Function<Double, Double> func) {
        double a = leftBound, b = rightBound;

        int iterationsNum = 0;
        double condition = (rightBound - leftBound) / eps;
        while (fibonacciNum(iterationsNum++) - condition <= 0);
        iterationsNum--;
        double fibonacciN2 = fibonacciNum(iterationsNum);
        double x1 = a + (b - a) / fibonacciN2 * fibonacciNum(iterationsNum - 2);
        double x2 = a + (b - a) / fibonacciN2 * fibonacciNum(iterationsNum - 1);
        double fX1 = func.apply(x1);
        double fX2 = func.apply(x2);
        for (int k = iterationsNum - 1; k > 1; k--) {
            if (fX1 - fX2 <= 0) {
                b = x2;
                x2 = x1;
                fX2 = fX1;
                x1 = a + (b - x2);
                fX1 = func.apply(x1);
            } else {
                a = x1;
                x1 = x2;
                fX1 = fX2;
                x2 = b - (x1 - a);
                fX2 = func.apply(x2);
            }
        }
        return (x1 + x2) / 2;
    }

    private int fibonacciNum(int k) {
        return k <= 1 ? 1 : fibonacciNum(k - 1) + fibonacciNum(k - 2);
    }
}