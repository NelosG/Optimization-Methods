package secondLab;

import org.apache.commons.math3.linear.ArrayRealVector;
import org.apache.commons.math3.linear.RealVector;

public class GradientDescent extends AbstractSolver {
    public GradientDescent(QuadraticFunction quadraticFunction, double epsilon) {
        super(quadraticFunction, epsilon);
    }

    @Override
    protected Pair calcMin(RealVector x, double xFunc, RealVector gradient, double length) {

        while (length >= epsilon) {
            ++iterations;
            RealVector y = x.add(gradient.mapMultiply(-alpha / length));
            double yFunc = quadraticFunction.apply(y);
            if (xFunc > yFunc) {
                x = y;
                xFunc = yFunc;
                gradient = quadraticFunction.gradient(x);
                length = VectorHelper.length(gradient);

            } else {
                alpha /= 2;
            }
        }

        return new Pair(x, xFunc);
    }
}
