package secondLab;

import org.apache.commons.math3.linear.ArrayRealVector;
import org.apache.commons.math3.linear.RealVector;


public abstract class AbstractSolver {
    protected double epsilon, alpha;
    protected long iterations, allIterations;
    protected QuadraticFunction quadraticFunction;

    public AbstractSolver(QuadraticFunction quadraticFunction, double epsilon) {
        this.epsilon = epsilon;
        this.quadraticFunction = quadraticFunction;
        this.alpha = 10;
    }

    public Pair findMin() {
        RealVector x = new ArrayRealVector(quadraticFunction.getN());
        double xFunc = quadraticFunction.apply(x);
        RealVector gradient = quadraticFunction.gradient(x);
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
