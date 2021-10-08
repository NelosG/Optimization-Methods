package secondLab;

import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.linear.RealVector;

import java.util.function.Function;

public abstract class QuadrFunction implements Function<RealVector, Double> {

    protected RealVector b;
    protected double c;
    protected int n;

    public abstract RealVector gradient(RealVector vector);

    public int size() {
        return n;
    }

    public abstract RealVector mulAToVec(RealVector vector);

    public abstract double rBound();

    public double lBound() {
        return 0;
    }
}
