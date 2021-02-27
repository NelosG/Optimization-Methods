package lab1;

import java.util.function.Function;

public interface Optimizer{
    public double optimize(double l, double r, double eps, Function<Double, Double> func);
}
