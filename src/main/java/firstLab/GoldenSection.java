package firstLab;

import java.util.function.Function;

public class GoldenSection implements Optimizer {

    private static final double TAU = (Math.sqrt(5) - 1) / 2;


    @Override
    public double optimize(double l, double r, double eps, Function<Double, Double> func){
        double a = l, b = r;
        double x1 = a + (3 - Math.sqrt(5)) * (b - a) / 2;
        double x2 = a + (Math.sqrt(5) - 1) * (b - a) / 2;
        double fX1 = func.apply(x1);
        double fX2 = func.apply(x2);
        while ((b - a) / 2 > eps) {
            if (fX1 - fX2 <= 0) {
                b = x2;
                x2 = x1;
                fX2 = fX1;
                x1 = b - TAU * (b - a);
                fX1 = func.apply(x1);
            } else {
                a = x1;
                x1 = x2;
                fX1 = fX2;
                x2 = a + TAU * (b - a);
                fX2 = func.apply(x2);
            }
        }
        return (a + b) / 2;
    }
}
