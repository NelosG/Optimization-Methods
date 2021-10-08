package firstLab;

import logs.Logger;

import java.util.ArrayList;
import java.util.function.Function;

public class Fibonacci extends Optimizer {

    private static final ArrayList<Integer> fibonacciCache = new ArrayList<>();

    static {
        fibonacciCache.add(1);
        fibonacciCache.add(1);
    }

    public Fibonacci() {
        super();
    }

    public Fibonacci(Logger l) {
        super(l);
    }

    @Override
    public double optimize(double leftBound, double rightBound, double eps, Function<Double, Double> func) {
        double a = leftBound, b = rightBound;
        int iterationsNum = 0;
        double condition = (rightBound - leftBound) / eps;
        while (fibonacciNum(iterationsNum++) - condition <= 0) ;
        iterationsNum--;
        double x1 = a + (b - a) / fibonacciNum(iterationsNum) * fibonacciNum(iterationsNum - 2);
        double x2 = a + (b - a) / fibonacciNum(iterationsNum) * fibonacciNum(iterationsNum - 1);
        double fX1 = func.apply(x1);
        double fX2 = func.apply(x2);

        forLog("iter N(to " + iterationsNum + ")", "x1", "x2", "fX1", "fX2", "a", "b",
                "length", "prev/now");
        double prev = 0;
        for (iterations = 1; iterations <= iterationsNum; iterations++) {
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
            forLog( iterations, x1, x2, fX1, fX2, a, b, Math.abs(a-b), prev/(Math.abs(a-b)));
            // x1 ? x2 ??? ? ??? ????? ????? ??? ????? ???/ a ? b ???????
            toMass(x1, fX1, x2, fX2, a, func.apply(a), b, func.apply(b));

            prev = Math.abs(a-b);
        }
        return (x1 + x2) / 2;
    }

    private int fibonacciNum(int k) {
        if (fibonacciCache.size() <= k) {
            int fibK = fibonacciNum(k - 1) + fibonacciNum(k - 2);
            fibonacciCache.add(fibK);
        }

        return fibonacciCache.get(k);
    }
}