package firstLab;

import logs.Logger;

import java.util.function.Function;

public class Dichotomy extends Optimizer {

    public Dichotomy() {
        super();
    }

    public Dichotomy(Logger l) {
        super(l);
    }

    @Override
    public double optimize(double l, double r, double eps, Function<Double, Double> func) {
        forLog("iter N", "x1", "x2", "f1", "f2", "l", "r", "abs(r-l)", "prev/now");
        forLog(0, "null", "null", "null", "null", l, r, Math.abs(r-l), 0);
        double prev = 0;
        iterations = 0;
        while ((r - l) / 2 > eps) {
            iterations++;
            double x1 = (l + r - eps) / 2;
            double x2 = (l + r + eps) / 2;
            double f1 = func.apply(x1);
            double f2 = func.apply(x2);
            if (f1 <= f2) {
                r = x2;
            } else {
                l = x1;
            }
            forLog(iterations,x1, x2, f1, f2, l, r, Math.abs(r-l), prev/(Math.abs(r-l)));
            // x1 ? x2 ????? ????? ???????? ????? ???/ l ? r - ???????
            toMass(x1, f1, x2, f2, l, func.apply(l), r, func.apply(r));
            prev = Math.abs(r-l);
        }
        return (l + r) / 2;
    }
}
