package firstLab;

import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.*;

import java.io.FileOutputStream;
import java.io.IOException;

public class Logger {

    public static Workbook book = new HSSFWorkbook();
    public static String outPutFile = ".\\Log.xls";
    private Sheet sheet;
    private int rowN;
    private int cell;
    private Row row;
    private int maxCell = 0;
    private boolean changed = false;

    public Logger(String sh) {
        this(sh, false);
    }

    public Logger(String sh, boolean add) {
        sheet = book.getSheet(sh);
        if (sheet == null) {
            sheet = book.createSheet(sh);
            rowN = 0;
            cell = 0;
        } else {
            if (add)
                while (sheet.getRow(rowN) != null) {
                    rowN++;
                }
        }
        row = sheet.createRow(rowN);
    }


    public void writeInFile() throws IOException {
        writeInFile(outPutFile);
    }

    public void writeInFile(String out) throws IOException {
        for (int i = 0; i < maxCell; i++) {
            sheet.autoSizeColumn(i);
        }
        book.write(new FileOutputStream(out));
        changed = false;
    }

    public void close() throws IOException {
        if(changed)writeInFile();
        book.close();
    }

    public void nextLine() {
        rowN++;
        cell = 0;
        row = sheet.createRow(rowN);
    }

    public void write(Object... s) {
        for (Object ss : s) {
            write(ss);
        }
        changed = true;
    }

    public void writeln(Object... s) {
        write(s);
        nextLine();
    }

    private void write(Object s) {
        Cell c = row.createCell(this.cell++);
        if (s.getClass() == Integer.class) {
            c.setCellValue((Integer) s);
        } else if (s.getClass() == Double.class) {
            c.setCellValue((Double) s);
        } else if (s.getClass() == String.class) {
            c.setCellValue((String) s);
        } else throw new IllegalArgumentException("Object not Integer, Double or String");
        if (cell > maxCell) maxCell = cell;
    }
}