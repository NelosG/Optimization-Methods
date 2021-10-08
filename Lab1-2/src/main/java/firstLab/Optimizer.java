package firstLab;

import logs.Logger;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.function.Function;
import java.util.stream.Collectors;

public abstract class Optimizer {
    public Logger log;
    public boolean toLog;
    public boolean generateMass = false;
    public long iterations = 0;



    public ArrayList<ArrayList<Pair<Double>>> array = null;

    public Optimizer() {
        this(null);
    }

    public Optimizer(Logger l) {
        log = l;
        toLog = log != null;
    }

    public double optimize(double l, double r, double eps, Function<Double, Double> func) {
        return 0;
    }

    public void forLog(Object... o) {
        if(toLog)
            log.writeln(o);

    }

    public void toMass(Number... o) {
        if(generateMass) {
            ArrayList<Pair<Double>> temp = new ArrayList<>();
            int k = 0;
            Pair<Double> p = new Pair<>(0.,0.);
            for(Object s : o) {
                if(k % 2 == 1) {
                    p.second = toDouble(s);
                    temp.add(p);
                    p =new Pair<>(0.,0.);
                } else {
                    p.first = toDouble(s);
                }
                k++;
            }
            if (!temp.isEmpty())
                array.add(temp);
        }
    }

    public void setGenerateMass(boolean flag){
        generateMass = flag;
        if(array == null) {
            array = new ArrayList<>();
        }
    }

    static Double toDouble(Object s) {
        if(s instanceof Integer)
            return (Double)(double)(int) s;
        if(s instanceof Long)
            return (Double)(double)(long) s;
        return (Double)s;
    }

    public static class Pair <T> {
        public T first, second;
        public Pair(T a, T b) {
            this.first = a;
            this.second = b;
        }
    }

    public long getIterations() {
        return iterations;
    }

    public long resetIterations() {
        long temp = iterations;
        iterations = 0;
        return temp;
    }
}



