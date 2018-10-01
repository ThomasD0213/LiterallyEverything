/**
 * PROGRAM NAME: HelpDesk.java
 * PROGRAM PURPOSE: Create a "basic" help desk tool.
 * DATES WRITTEN: 9-26-2018 - ?
 * PROGRAMMERS: Aaron Fesh and Thomas Dalgetty
 */

/*
    IDEAS:
        3 different branches to start
            -Hardware questions
            -Software questions
            -Tech support
                *leads to an email or phone number
            -Each branch would have 2 or 3 solns with 2 or 3 steps per question
                *if the question isn't answered by the end it'll lead to tech support num/email
            -Basic gui with buttons, not a console program (be nice to have)


*/

/*
*                   TODO BLOCK
*  TODO: read path from Path.txt for ease of use
*  TODO: add UI using swing or JavaFX or improve text based UI
*  TODO: When UI is added update Path.txt using user input if Path.txt is empty
*
* */


import java.io.*;
import java.util.*;
import java.nio.file.Path;
import java.nio.file.Paths;

public class HelpDesk implements HelpMethods {
    private ArrayList<String> hardwareAnswers; //contains answers for the most common hardware questions
    private ArrayList<String> softwareAnswers; //contains answers for the most common software questions
    private ArrayList<String> techSuppAnswers; //contains general tech support answers
    private ArrayList<String> hardwareQuestions; //contains general hardware questions
    private ArrayList<String> softwareQuestions; //contains general software questions
    private ArrayList<String> techSuppQuestions; //contains general techsupport questions

    private File hardwareAnswerFile =       new File("hardwareanswers.txt"); //this file is used to populate hardwareAnswers in constructor
    private File softwareAnswerFile =       new File("softwareanswers.txt"); //this file is used to populate softwareAnswers in constructor
    private File techSuppAnswerFile =       new File("techsupportanswers.txt"); //this file is used to populate techSuportAnswers in constructor
    private File hardwareQuestionFile =     new File("hardwarequestions.txt");
    private File softwareQuestionFile =     new File("softwarequestions.txt");
    private File techSuppQuestionFile =     new File("techsupportquestions.txt");

    private BufferedReader hardwareAnsReader;
    private BufferedReader softwareAnsReader;
    private BufferedReader techSuppAnsReader;
    private BufferedReader hardwareQueReader;
    private BufferedReader softwareQueReader;
    private BufferedReader techSuppQueReader;

    public HelpDesk() {
        try {
            hardwareAnsReader = new BufferedReader(new FileReader(hardwareAnswerFile));
            softwareAnsReader = new BufferedReader(new FileReader(softwareAnswerFile));
            techSuppAnsReader = new BufferedReader(new FileReader(techSuppAnswerFile));
            hardwareQueReader = new BufferedReader(new FileReader(hardwareQuestionFile));
            softwareQueReader = new BufferedReader(new FileReader(softwareQuestionFile));
            techSuppQueReader = new BufferedReader(new FileReader(techSuppQuestionFile));
        }
        catch(IOException e) {
            e.printStackTrace();
        }
        hardwareAnswers =   new ArrayList<String>();
        hardwareQuestions = new ArrayList<String>();
        softwareAnswers =   new ArrayList<String>();
        softwareQuestions = new ArrayList<String>();
        techSuppAnswers =   new ArrayList<String>();
        techSuppQuestions = new ArrayList<String>();

        long hardwareLines = hardwareAnsReader.lines().count();
        long softwareLines = softwareAnsReader.lines().count();
        long techSuppLines = techSuppAnsReader.lines().count();

        try {
            hardwareAnsReader = new BufferedReader(new FileReader(hardwareAnswerFile)); //fixes issue of buffer not being ready to read. just resets the buffer.
            softwareAnsReader = new BufferedReader(new FileReader(softwareAnswerFile)); //fixes issue of buffer not being ready to read. just resets the buffer.
            techSuppAnsReader = new BufferedReader(new FileReader(techSuppAnswerFile)); //fixes issue of buffer not being ready to read. just resets the buffer.
            for (int i = 0; i < hardwareLines; i++) //populate hardwareAnswers and hardwareQuestions size should be the same between the two
            {
                hardwareAnswers.add(hardwareAnsReader.readLine());
                hardwareQuestions.add(hardwareQueReader.readLine());
                // System.out.println(hardwareAnsReader.lines().count() + " hardware answer reader");
            }
            for(int i = 0; i < softwareLines; i++) //populate softwareAnswers and softwareQuestions size should be the same between the two
            {
                softwareAnswers.add(softwareAnsReader.readLine());
                softwareQuestions.add(softwareQueReader.readLine());
            }
            for(int i = 0; i < techSuppLines; i++) //populate techSuppAnswers and techSuppQuestions size should be the same between the two
            {
                techSuppAnswers.add(techSuppAnsReader.readLine());
                techSuppQuestions.add(techSuppQueReader.readLine());
            }
            hardwareAnsReader.close();
            softwareAnsReader.close();
            techSuppAnsReader.close();
            hardwareQueReader.close();
            softwareQueReader.close();
            techSuppQueReader.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }


    public String getAnswer(int array, int index) //requests a question for the user
    {
        switch (array) {
            case 1:
                return (index >= hardwareAnswers.size())? index + " does not exist!" : hardwareAnswers.get(index);
            case 2:
                return (index >= softwareAnswers.size())? index + " does not exist!" : softwareAnswers.get(index);
            case 3:
                return (index >= techSuppAnswers.size())? index + " does not exist!" : techSuppAnswers.get(index);
            default:
                return array + " is not a valid input!";
        }
    }

    public String getQuestion(int array, int index)
    {
        switch (array) {
            case 1:
                return (index >= hardwareQuestions.size())? index + " does not exist!" : hardwareQuestions.get(index);
            case 2:
                return (index >= softwareQuestions.size())? index + " does not exist!" : softwareQuestions.get(index);
            case 3:
                return (index >= techSuppQuestions.size())? index + " does not exist!" : techSuppQuestions.get(index);
            default:
                return array + " is not a valid input!";
        }
    }

    public void listToString(ArrayList<String> list){
        int i = 0;
        for(String element : list) {
            System.out.println(i + ": " + element);
            i++;
        }

    }
    public ArrayList<String> getHardwareQuestions() { return hardwareQuestions; }
    public ArrayList<String> getHardwareAnswers()   { return hardwareAnswers; }
    public ArrayList<String> getSoftwareQuestions() { return softwareQuestions; }
    public ArrayList<String> getSoftwareAnswers()   { return softwareAnswers; }
    public ArrayList<String> getTechSuppAnswers()   { return techSuppAnswers; }
    public ArrayList<String> getTechSuppQuestions() { return techSuppQuestions; }



}