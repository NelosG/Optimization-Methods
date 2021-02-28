package firstLab;

import java.util.function.Function;

public class Fibonacci implements Optimizer {


    @Override
    public double optimize(double l, double r, double eps, Function<Double, Double> func){

        int iterationsNum = 0, fibN2 = fibonacciNum(2);
        double condition = (r - l) / eps;
        while (fibN2 - condition <= 0) {
            iterationsNum++;
            fibN2 = fibonacciNum(iterationsNum  + 2);
        }
        int fibonacciN2 = fibN2;


        double a = l, b = r;
        double x1 = a + fibonacciNum(iterationsNum) * (b - a) / fibonacciN2;
        double x2 = a + fibonacciNum(iterationsNum + 1) * (b - a) / fibonacciN2;
        double fX1 = func.apply(x1);
        double fX2 = func.apply(x2);
        for (int k = 1; k <= iterationsNum; k++) {
            if (fX1 - fX2 <= 0) {
                b = x2;
                x2 = x1;
                fX2 = fX1;
                x1 = a + fibonacciNum(iterationsNum - k + 1) * (r - l) / fibonacciN2;
                fX1 = func.apply(x1);
            } else {
                a = x1;
                x1 = x2;
                fX1 = fX2;
                x2 = a + fibonacciNum(iterationsNum - k + 2) * (r - l) / fibonacciN2;
                fX2 = func.apply(x2);
            }
        }
        return (b + a) / 2;
    }

    private int fibonacciNum(int k) {
        if (k <= 1) {
            return 1;
        }
        return fibonacciNum(k - 1) + fibonacciNum(k - 2);
    }
}