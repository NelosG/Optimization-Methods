public class Main {
    public static void main(String[] args) {
        new Runner(true).addTask(new Task("SeventhExpression",
                x -> Math.pow(Math.log10(x - 2), 2.0) + Math.pow(Math.log10(10 - x), 2.0) - Math.pow(x, 0.2),
                6., 9.9,8.72691,-0.846037))
//                .addForRun("Dichotomy", 1.E-15)
//                .addForRun("Fibonacci", 1.E-8)
//                .addForRun("GoldenSection", 1.E-15)
//                .addForRun("Parabolas", 1.E-8) //::TODO выдает фигню при эпс < 1.E-8
                .addForRun("Brent", 1.E-8) //::TODO фиговая точность, нормально ток на 1.E-8
                .runTasks();
    }
}
