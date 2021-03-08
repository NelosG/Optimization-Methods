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
        int k = 0;
        while (r - l > eps) {
            double chisl =Math.pow(x - l, 2) * (fx - fr) -Math.pow(x - r, 2) * (fx - fl);
            double znam = (2 * ((x - l) * (fx - fr) - (x - r) * (fx - fl)));
            //to protect from NaN
            if(chisl == 0.0 && znam == 0.0) {
                if( x == u)
                    break;
                u = x;
            } else u = x - chisl / znam;
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
            k++;
        }
        System.out.println("EPSILON = " + eps + " Step: " + k);
        return (l + r) / 2;
    }
}
