import firstLab.Logger;
import firstLab.Optimizer;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.function.Function;

public class RunSixthExpression {

    public static void main(String[] args) {
        try {
            Files.createDirectory(Path.of(".\\Logs"));

        } catch (Exception ignored) {}
        Logger logger = new Logger();
        for (int i = 1; i < 16; i++) {
            run("Dichotomy", -i);
            run("GoldenSection", -i);
            if(i < 9) run("Fibonacci", -i);
            try {
                logger.reset(true);
            } catch (Exception ignored) {}
        }
    }

    static void run(String name, int n) {
        Optimizer optimizer = null;
        try {
            optimizer = (Optimizer) Class.forName("firstLab." + name).getDeclaredConstructor(Logger.class).newInstance(new Logger());
        } catch (final ClassNotFoundException e) {
            e.printStackTrace();
        } catch (final Exception e) {
            System.err.println("Can't create optimizer");
            e.printStackTrace();
        }


        assert optimizer != null;
        optimizer.log.addSheet(name, false);
        Function<Double, Double> func = x -> Math.pow(Math.log10(x - 2), 2.0) + Math.pow(Math.log10(10 - x), 2.0) - Math.pow(x, 0.2);
        double resultX = optimizer.optimize(6., 9.9, Math.pow(10., n), func);
        double resultY = func.apply(resultX);
        optimizer.log.writeln("Expected:", "x: " + 8.72691, "y: " + -0.846037);
        optimizer.log.writeln("Actual:", "x: " + resultX, "y: " + resultY);
        optimizer.log.writeln("Difference:", "x: " + Math.abs(8.72691-resultX), "y: " + Math.abs(-0.846037-resultY));
        try {
            optimizer.log.writeInFile(".\\Logs\\eps10e" + (n-1) + "Log.xls");
        } catch (IOException e) {
            System.err.println("Can't write log");
        }
    }
}
