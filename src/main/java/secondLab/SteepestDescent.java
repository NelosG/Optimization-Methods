package secondLab;

import firstLab.Optimizer;
import org.apache.commons.math3.linear.RealVector;

import java.util.function.Function;

public class SteepestDescent extends AbstractSolver {
    Optimizer optimizer;


    public SteepestDescent(QuadraticFunction quadraticFunction, double epsilon,  Optimizer opt) {
        super(quadraticFunction, epsilon);
        optimizer = opt;
    }

    @Override
    protected Pair calcMin(RealVector x, double xFunc, RealVector gradient, double length) {
        while (length >= epsilon) {
            ++iterations;
            nextIter(x, gradient);
            x = x.add(gradient.mapMultiply(-alpha));
            gradient = quadraticFunction.gradient(x);
            length = VectorHelper.length(gradient);
        }
        return new Pair(x, quadraticFunction.apply(x));
    }

    private void nextIter(RealVector x, RealVector gradient) {
        Function<Double, Double> functionAlpha = a -> quadraticFunction.apply(x.copy().add(gradient.mapMultiply(-a)));
        alpha = optimizer.optimize(0, MatrixHelper.getMaxEigenValue(quadraticFunction.getA()), epsilon, functionAlpha);
        allIterations += optimizer.resetIterations();
    }
}
