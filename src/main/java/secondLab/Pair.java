package secondLab;

import org.apache.commons.math3.linear.RealVector;

public class Pair {
    private RealVector value;
    private double funcValue;

    public Pair(RealVector value, double funcValue) {
        this.value = value;
        this.funcValue = funcValue;
    }

    public RealVector getValue() {
        return value;
    }

    public void setValue(RealVector value) {
        this.value = value;
    }

    public double getFuncValue() {
        return funcValue;
    }

    public void setFuncValue(double funcValue) {
        this.funcValue = funcValue;
    }
}
