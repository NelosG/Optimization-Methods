package secondLab;

import org.apache.commons.math3.linear.RealVector;


public class ConjugateGradient extends AbstractSolver {

    public ConjugateGradient(QuadrFunction quadrFunction, double epsilon) {
        super(quadrFunction, epsilon);
    }

    @Override
    protected Pair calcMin(RealVector x, double xFunc, RealVector gradient, double length) {
        RealVector vectorP = gradient.mapMultiply(-1);
        while (length >= epsilon) {
            ++iterations;
            RealVector ap = quadrFunction.mulAtoVec(vectorP);
            alpha = length / ap.dotProduct(vectorP);
            RealVector nextX = x.add(vectorP.mapMultiply(alpha));
            RealVector nextGradient = gradient.add(ap.mapMultiply(alpha));
            double nextGradientLength = nextGradient.dotProduct(nextGradient);
            double beta;
            if (iterations % x.getDimension() == 0) {
                beta = 0;
            } else {
                beta = nextGradientLength / length;
            }
            vectorP = nextGradient.mapMultiply(-1).add(vectorP.mapMultiply(beta));
            gradient = nextGradient;
            length = nextGradientLength;
            x = nextX;
        }
        return new Pair(x, quadrFunction.apply(x));
    }
}
