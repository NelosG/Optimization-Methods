package firstLab;

import java.util.function.Function;

public class Dichotomy extends Optimizer {

    public Dichotomy() {
        log = new Logger("Dichotomy");
    }

    public Dichotomy(Logger l) {
        log = l;
    }

    @Override
    public double optimize(double l, double r, double eps, Function<Double, Double> func) {
        log.writeln("x1", "x2", "f1", "f2", "l", "r");
        log.writeln("null", "null", "null", "null", l, r);
        while ((r - l) / 2 > eps) {
            double x1 = (l + r - eps) / 2;
            double x2 = (l + r + eps) / 2;
            double f1 = func.apply(x1);
            double f2 = func.apply(x2);
            if (f1 < f2) {
                r = x2;
            } else {
                l = x1;
            }
            log.writeln(x1, x2, f1, f2, l, r);
        }
        return (l + r) / 2;
    }
}
