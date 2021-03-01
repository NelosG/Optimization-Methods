public class Main {
    public static void main(String[] args) {
        new Runner().addTask(new Task("SixthExpression",
                x -> Math.pow(Math.log10(x - 2), 2.0) + Math.pow(Math.log10(10 - x), 2.0) - Math.pow(x, 0.2),
                6., 9.9,8.72691,-0.846037))
                .addForRun("Dichotomy", 1.E-15)
                .addForRun("Fibonacci", 1.E-8)
                .addForRun("GoldenSection", 1.E-15)
                .runTasks();
    }
}
