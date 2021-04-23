package secondLab;

import org.apache.commons.math3.linear.ArrayRealVector;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;

import java.util.ArrayList;
import java.util.List;


public class ConjugateGradient extends AbstractSolver {

    public ConjugateGradient(QuadraticFunction quadraticFunction, double epsilon) {
        super(quadraticFunction, epsilon);
    }

    @Override
    protected Pair calcMin(RealVector x, double xFunc, RealVector gradient, double length) {
        RealVector vectorP = gradient.mapMultiply(-1);
        while (length >= epsilon) {
            ++iterations;
            RealVector ap = MatrixHelper.mul(quadraticFunction.getA(),(vectorP));
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
        return new Pair(x, quadraticFunction.apply(x));
    }
}
