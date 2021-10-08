package secondLab;

import org.apache.commons.math3.linear.RealVector;


public class ConjugateGradient extends AbstractSolver {

    public ConjugateGradient(QuadrFunction quadrFunction, double epsilon) {
        super(quadrFunction, epsilon);
    }

    @Override
    protected Pair calcMin(RealVector x, double xFunc, RealVector gradient, double length) {
        iterations = 0;
        double lambda, beta, newLength;
        RealVector p, newX, g1, g;
        g1 = quadrFunction.gradient(x);
        p = g1.mapMultiply(-1);
        while (length > epsilon) {
            ++iterations;
            newX = x;
            g = g1;
            RealVector apk = quadrFunction.mulAToVec(p);
            double f = apk.dotProduct(p);
            length = g.dotProduct(g);
            lambda = length / f;
            x = newX.combine(1, lambda, p);
            if (iterations % quadrFunction.n == 0) {
                g1 = quadrFunction.gradient(x).mapMultiply(-1);
            } else {
                g1 = g.combine(1, lambda, apk);
                newLength = g1.dotProduct(g1);
                beta = newLength/length;
                p = quadrFunction.gradient(x).combine(-1, beta, p);
            }
        }
        return new Pair(x, quadrFunction.apply(x));
    }
}
