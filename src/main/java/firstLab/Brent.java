package firstLab;

import java.util.ArrayList;
import java.util.function.Function;

public class Brent extends Optimizer {

    public Brent() {
        super();
    }

    public Brent(Logger l) {
        super(l);
    }


    //::TODO падает на 7 тесте
    @Override
    public double optimize(double l, double r, double eps, Function<Double, Double> func) {
        double k = (3 - Math.sqrt(5)) / 2;
        double x, w, v;
        double a = l;
        double c = r;
        x = w = v = (a + c) / 2;
        double fx, fw, fv;
        fx = fw = fv = func.apply(x);
        double d, e;
        d = e = c - a;
        while (d > eps) {
            double g;
            g = e;
            e = d;
            double u;
            if (!(fx == fw || fx == fv || fv == fw)) {
                u = x - (Math.pow((x - w), 2) * (fx - fv) -
                        Math.pow((x - v), 2) * (fx - fw)) / (2 * ((x - w) * (fx - fv) - (x - v) * (fx - fw)));

                if (u >= a + eps && u <= c - eps && Math.abs(u - x) < g / 2) {
                    d = Math.abs(u - x);
                } else {
                    if (x < (c - a) / 2) {
                        u = a + k * (c - x);
                        d = c - x;
                    } else {
                        u = c - k * (x - a);
                        d = x - a;
                    }
                }
            } else {
                if (x < (c - a) / 2) {
                    u = x + k * (c - x);
                    d = c - x;
                } else {
                    u = x - k * (x - a);
                    d = x - a;
                }
                if (Math.abs(u - x) < eps) {
                    u = x + Math.signum(u - x) * eps;
                }
            }
            double fu = func.apply(u);
            if (fu <= fx) {
                if (u >= x) {
                    a = x;
                } else {
                    c = x;
                }
                v = w;
                w = x;
                x = u;
                fv = fw;
                fw = fx;
                fx = fu;
            } else {
                if (u >= x) {
                    c = u;
                } else {
                    a = u;
                }
                if (fu <= fw || w == x) {
                    v = w;
                    w = u;
                    fv = fw;
                    fw = fu;
                } else {
                    if (fu <= fv || v == x || v == w) {
                        v = u;
                        fv = fu;
                    }
                }
            }
        }
        return (a + c) / 2;
    }
}