package secondLab;

import firstLab.Optimizer;
import org.apache.commons.math3.linear.RealVector;

import java.util.function.Function;

public class SteepestDescent extends AbstractSolver {
    Optimizer optimizer;


    public SteepestDescent(QuadrFunction quadrFunction, double epsilon, Optimizer opt) {
        super(quadrFunction, epsilon);
        optimizer = opt;
    }

    @Override
    protected Pair calcMin(RealVector x, double xFunc, RealVector gradient, double length) {
        while (length >= epsilon) {
            ++iterations;
            nextIter(x, gradient);
            x = x.add(gradient.mapMultiply(-alpha));
            gradient = quadrFunction.gradient(x);
            length = VectorHelper.length(gradient);
            if(iterations > 100_000) {
                ++iterations;
                break;
            }
        }
        return new Pair(x, quadrFunction.apply(x));
    }

    private void nextIter(RealVector x, RealVector gradient) {
        Function<Double, Double> functionAlpha = a -> quadrFunction.apply(x.add(gradient.mapMultiply(-a)));
        alpha = optimizer.optimize(quadrFunction.lBound(), quadrFunction.rBound(), epsilon, functionAlpha);
        allIterations += optimizer.resetIterations();
    }
}
