package secondLab;

import org.apache.commons.math3.linear.RealVector;

public class GradientDescent extends AbstractSolver {
    public GradientDescent(QuadrFunction quadrFunction, double epsilon) {
        super(quadrFunction, epsilon);
    }

    @Override
    protected Pair calcMin(RealVector x, double xFunc, RealVector gradient, double length) {
        iterations = 0;
        while (length >= epsilon) {
            ++iterations;
            RealVector y = x.add(gradient.mapMultiply(-alpha / length));
            double yFunc = quadrFunction.apply(y);
            if (xFunc > yFunc) {
                x = y;
                xFunc = yFunc;
                gradient = quadrFunction.gradient(x);
                length = VectorHelper.length(gradient);

            } else {
                alpha /= 2;
            }
        }

        return new Pair(x, xFunc);
    }
}
