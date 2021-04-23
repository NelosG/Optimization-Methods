package secondLab;

import java.util.ArrayList;
import java.util.List;

public class Vector {
    private final List<Double> coefficients;

    public Vector(List<Double> coefficients) {
        this.coefficients = new ArrayList<>(coefficients);
    }

    public Vector(Vector vector) {
        this(vector.getCoefficients());
    }

    public Vector() {
        this(new ArrayList<>());
    }

    public Vector multiplyByScalar(double coefficient) {
        Vector result = new Vector();
        for (Double aDouble : coefficients) {
            result.add(aDouble * coefficient);
        }
        return result;
    }

    public Vector sum(Vector vector)  {
        Vector res = new Vector();
        for (int i = 0; i < vector.size(); i++) {
            res.add(coefficients.get(i) + vector.get(i));
        }
        return res;
    }

    public double scalarMultiplication(Vector vector) {
        double res = 0;
        for (int i = 0; i < vector.size(); i++) {
            res += this.coefficients.get(i) * vector.get(i);
        }
        return res;
    }

    public int size() {
        return coefficients.size();
    }

    public double length() {
        double length = 0;
        for (double c : coefficients) {
            length += c*c;
        }
        length = Math.sqrt(length);
        return length;
    }

    public double get(int index) {
        return coefficients.get(index);
    }

    public void add(double element) {
        coefficients.add(element);
    }


    public void set(int index, double element) {
        coefficients.set(index, element);
    }

    public List<Double> getCoefficients() {
        return coefficients;
    }

}
