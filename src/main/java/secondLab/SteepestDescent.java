package secondLab;

import firstLab.Optimizer;

import java.util.function.Function;

public class SteepestDescent extends AbstractSolver {
    Optimizer optimizer;


    public SteepestDescent(QuadraticFunction quadraticFunction, double epsilon,  Optimizer opt) {
        super(quadraticFunction, epsilon);
        optimizer = opt;
    }

    @Override
    protected Pair calcMin(Vector x, double xFunc, Vector gradient, double length) {
        while (length >= epsilon) {
            ++iterations;
            nextIter(x, gradient);
            x = x.sum(gradient.multiplyByScalar(-alpha));
            gradient = quadraticFunction.gradient(x);
            length = gradient.length();
        }
        return new Pair(x, quadraticFunction.apply(x));
    }

    private void nextIter(Vector x, Vector gradient) {
        Function<Double, Double> functionAlpha = a -> quadraticFunction.apply(x.sum(gradient.multiplyByScalar(-a)));
        alpha = optimizer.optimize(Integer.MIN_VALUE, Integer.MAX_VALUE, epsilon, functionAlpha);
        allIterations += optimizer.resetIterations();
    }
}
