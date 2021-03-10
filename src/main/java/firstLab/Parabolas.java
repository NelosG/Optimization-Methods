package firstLab;

import java.util.Random;
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
        double x = (l+r)/2.;
        double fx = func.apply(x);
        double u = 1.0/0.0;
        int k = 1;
        forLog("iter N", "u", "x", "l", "r", "prev/now");
        double prev = 0;
        while (r - l > eps) {
            double numerator =Math.pow(x - l, 2) * (fx - fr) -Math.pow(x - r, 2) * (fx - fl);
            double denominator = (2 * ((x - l) * (fx - fr) - (x - r) * (fx - fl)));
            //to protect from NaN
            if(numerator == 0.0 && denominator == 0.0) {
                if( x == u)
                    break;
                u = x;
            } else u = x - numerator / denominator;
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
            forLog(k, u, x, l, r, prev/(l + r) / 2);
            prev = (l + r) / 2;
            k++;
        }
        return (l + r) / 2;
    }
}
