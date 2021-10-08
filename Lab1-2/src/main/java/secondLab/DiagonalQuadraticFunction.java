package secondLab;

import org.apache.commons.math3.linear.RealVector;

public class DiagonalQuadraticFunction extends QuadrFunction {
    protected RealVector a;

    public DiagonalQuadraticFunction(RealVector a, RealVector b, double c) {
        super();
        this.n = b.getDimension();
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public RealVector mulAToVec(RealVector vector) {
        return mul(a, (vector));
    }

    @Override
    public Double apply(RealVector vector) {
        return (vector.dotProduct(mul(a, vector))) / 2
                + vector.dotProduct(b)
                + c;
    }

    @Override
    public RealVector gradient(RealVector vector) {
        return mul(a, vector).add(b);
    }

    @Override
    public double rBound() {
        return a.getMaxValue();
    }

    private RealVector mul(RealVector a, RealVector b) {
        return a.ebeMultiply(b);
    }
}