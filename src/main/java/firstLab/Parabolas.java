package firstLab;

import logs.Logger;

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
        double x = l + (r-l)*rand.nextDouble();
        double fx = func.apply(x);
        while(!(fl >= fx && fx <= fr)) {
            x = l + (r-l)*rand.nextDouble();
            fx = func.apply(x);
        }
        double u;
        iterations = 0;
        forLog("iter N", "u", "x", "l", "r", "abs(l-r)", "prev/now");
        double prev = 0;
        while ((r - l)/2 > eps) {
            iterations++;
            u = x - (Math.pow(x - l, 2) * (fx - fr) -Math.pow(x - r, 2) * (fx - fl)) / (2 * ((x - l) * (fx - fr) - (x - r) * (fx - fl)));
            if(Double.isNaN(u)) {
                break;
            }
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
            forLog(iterations, u, x, l, r, Math.abs(l-r), prev/Math.abs(l-r));
            // x - ??? ???/ u ??? ????????/ l ? r - ???????
            toMass(x, fx, u, fu,l, fl,  r, fr);
            prev = Math.abs(l-r);
        }
        return (l + r) / 2;
    }
}
