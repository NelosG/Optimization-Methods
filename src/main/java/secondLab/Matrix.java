package secondLab;

import java.util.ArrayList;
import java.util.List;

public class Matrix {
    private final List<Vector> matrix;

    public Matrix() {
        matrix = new ArrayList<>();
    }

    public Matrix(List<Vector> a) {
        matrix = new ArrayList<>();
        matrix.addAll(a);
    }

    public Vector multiplyByVector(Vector vector)  {
        Vector res = new Vector();
        for (Vector vec : matrix) {
            res.add(vec.scalarMultiplication(vector));
        }
        return res;
    }

    public double get(int ind1, int ind2) {
        return matrix.get(ind1).get(ind2);
    }

    public Vector get(int ind) {
        return matrix.get(ind);
    }

    public void set(int ind, Vector val) {
        matrix.set(ind, val);
    }

    public void set(int ind1, int ind2, Double val) {
        matrix.get(ind1).set(ind2, val);
    }


    public int size() {
        return matrix.size();
    }
}
