package secondLab;

public class Pair {
    private Vector value;
    private double funcValue;

    public Pair(Vector value, double funcValue) {
        this.value = value;
        this.funcValue = funcValue;
    }

    public Vector getValue() {
        return value;
    }

    public void setValue(Vector value) {
        this.value = value;
    }

    public double getFuncValue() {
        return funcValue;
    }

    public void setFuncValue(double funcValue) {
        this.funcValue = funcValue;
    }
}
