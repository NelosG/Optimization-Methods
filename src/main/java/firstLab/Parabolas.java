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
        Random rand = new Random();
        double x = l + rand.nextDouble() * (r - l);
        double fx = func.apply(x);
        while (!(fl > fx && fx < fr)) {
            x = l + rand.nextDouble() * (r - l);
            if(x == 0)
                x += 1E-323;
            fx = func.apply(x);
        }
        fx = func.apply(x);
        double u = 1.0/0.0;
        while (r - l > eps) {
            double chisl =Math.pow(x - l, 2) * (fx - fr) -Math.pow(x - r, 2) * (fx - fl);
            double znam = (2 * ((x - l) * (fx - fr) - (x - r) * (fx - fl)));
            //to protect from NaN
            if(chisl == 0.0 && znam == 0.0) {
                if( x == u)
                    break;
                u = x - 1;
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
        }
        return (l + r) / 2;
    }

    //Don't work

//    @Override
//    public double optimize(double l, double r, double eps, Function<Double, Double> f) {
//        double x = l + r / 2;
//        double h = 0.001;
//        if (x == 0) x += 0.1;
//        while ((f.apply(x + h) - 2 * f.apply(x) + f.apply(x - h)) / (h * h) <= 0)
//            x += 0.1;
//        double x1;
//        double XplH = f.apply(x + h);
//        double XmiH = f.apply(x - h);
//        x1 = x - 0.5 * h * (XplH - XmiH) / (XplH - 2 * f.apply(x) + XmiH);
//        while (Math.abs(x1 - x) > eps) {
//            x = x1;
//            XplH = f.apply(x + h);
//            XmiH = f.apply(x - h);
//            x1 = x - 0.5 * h * (XplH - XmiH) / (XplH - 2 * f.apply(x) + XmiH);
//        }
//        return x1;
//    }
}
