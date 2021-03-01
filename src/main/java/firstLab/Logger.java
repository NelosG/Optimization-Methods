package firstLab;

import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.CellUtil;

import java.io.FileOutputStream;
import java.io.IOException;

public class Logger {

    public static Workbook book = new HSSFWorkbook();
    public static String outPutFile = ".\\Optimization-Methods.xls";
    private Sheet sheet;
    private int rowN;
    private int cell;
    private Row row;
    private int maxCell = 0;

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
        for (int i = 0; i < maxCell; i++) {
            sheet.autoSizeColumn(i);
        }
        book.write(new FileOutputStream(outPutFile));
    }

    public void close() throws IOException {
        writeInFile();
        book.close();
    }

    public void nextLine() {
        rowN++;
        cell = 0;
        row = sheet.createRow(rowN);
    }

    public void write(String... s) {
        for (String ss : s) {
            write(ss);
        }
    }

    public void writeln(Object... s) {
        for (Object ss : s) {
            write(ss);
        }
        nextLine();
    }

    private void write(Object s) {
        Cell c = row.createCell(this.cell++);
        if(s.getClass() == Integer.class) {
            c.setCellValue((Integer)s);
        } else if(s.getClass() == Double.class) {
            c.setCellValue((Double)s);
        } else if(s.getClass() == String.class){
            c.setCellValue((String) s);
        } else throw new IllegalArgumentException("Object not Integer, Double or String");
        if(cell > maxCell) maxCell = cell;
    }
}
