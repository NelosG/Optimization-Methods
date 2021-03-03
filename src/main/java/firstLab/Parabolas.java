package firstLab;

import java.util.function.Function;

public class Parabolas extends Optimizer {

    public Parabolas() {
        super();
    }

    public Parabolas(Logger l) {
        super(l);
    }

    @Override
    public double optimize(double l, double r, double eps, Function<Double, Double> func) {
        double fl = func.apply(l);
        double fr = func.apply(r);
        double x = (l + r) / 2;
        double fx = func.apply(x);
        while (r - l > eps) {
            double u = x - (Math.pow(x - l, 2) * (fx - fr) - Math.pow(x - r, 2) * (fx - fl)) / (2 * ((x - l) * (fx - fr) - (x - r) * (fx - fl)));
            double fu = func.apply(u);
            if (fu > fx) {
                if (u > x) {
                    r = u;
                    fr = fu;
                } else {
                    l = u;
                    fl = fu;
                }
            } else {
                if (x > u) {
                    r = x;
                    fr = fx;
                } else {
                    l = x;
                    fl = fx;
                }
                x = u;
                fx = fu;
            }
        }
        return (l + r) / 2;
    }
}
