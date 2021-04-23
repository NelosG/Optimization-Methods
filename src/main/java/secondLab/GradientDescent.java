package secondLab;

public class GradientDescent extends AbstractSolver {
    public GradientDescent(QuadraticFunction quadraticFunction, double epsilon) {
        super(quadraticFunction, epsilon);
    }

    @Override
    protected Pair calcMin(Vector x, double xFunc, Vector gradient, double length) {
        while (length >= epsilon) {
            ++iterations;
            Vector y = x.sum(gradient.multiplyByScalar(-alpha / length));
            double yFunc = quadraticFunction.apply(y);
            if (xFunc > yFunc) {
                x = new Vector(y);
                xFunc = yFunc;
                gradient = quadraticFunction.gradient(x);
                length = gradient.length();
            } else {
                alpha /= 2;
            }
        }

        return new Pair(x, xFunc);
    }
}
