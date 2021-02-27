package firstLab;

import java.util.function.Function;

public interface Optimizer{
    double optimize(double l, double r, double eps, Function<Double, Double> func);
}
