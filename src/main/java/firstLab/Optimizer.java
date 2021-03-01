package firstLab;

import java.util.function.Function;

public abstract class Optimizer {
    public Logger log;
    public boolean toLog;

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
}
