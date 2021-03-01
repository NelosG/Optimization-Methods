package firstLab;

import java.util.function.Function;

public abstract class Optimizer {
    public Logger log;

    public double optimize(double l, double r, double eps, Function<Double, Double> func) {
        return 0;
    }
}
