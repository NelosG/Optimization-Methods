package secondLab;

import org.apache.commons.math3.linear.ArrayRealVector;
import org.apache.commons.math3.linear.RealVector;


public abstract class AbstractSolver {
    protected double epsilon, alpha = 10;
    protected long iterations, allIterations;
    protected QuadrFunction quadrFunction;

    public AbstractSolver(QuadrFunction quadrFunction, double epsilon) {
        this.epsilon = epsilon;
        this.quadrFunction = quadrFunction;
    }

    public Pair findMin() {
        RealVector x = new ArrayRealVector(quadrFunction.size());
        double xFunc = quadrFunction.apply(x);
        RealVector gradient = quadrFunction.gradient(x);
        double length = VectorHelper.length(gradient);
        if (length < epsilon) {
            return new Pair(x, xFunc);
        }
        Pair forRet = calcMin(x, xFunc, gradient, length);
        allIterations += iterations;
        return forRet;
    }

    public long getIterations() {
        return iterations;
    }

    public long getAllIterations() {
        return allIterations;
    }

    public long resetIterations() {
        long temp = allIterations;
        iterations = 0;
        allIterations = 0;
        return temp;
    }

    protected abstract Pair calcMin(RealVector x, double xFunc, RealVector gradient, double length);
}
