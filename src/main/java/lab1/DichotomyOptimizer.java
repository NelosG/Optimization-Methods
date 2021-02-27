package lab1;

import java.util.function.Function;

public class DichotomyOptimizer implements Optimizer {
    @Override
    public double optimize(double l, double r, double eps, Function<Double, Double> func){
        double mid;
        while(r - l > eps){
            mid = (l + r)/2;
            double f1 = func.apply(mid - eps);
            double f2 = func.apply(mid + eps);
            if(f1 < f2){
                r = mid;
            } else {
                l = mid;
            }
        }
        return (l + r)/2;
    }
}
