import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class password extends JFrame implements  ActionListener{
    JLabel l1,l2,l3;
    JButton b1,b2;
    JTextField t1,t2;
    password(){
        setLayout(new FlowLayout());
        l1=new JLabel("Random Password Generator!!!");
        l1.setForeground(Color.RED);
        l1.setFont(new Font("Arial", Font.CENTER_BASELINE, 25));
        l2=new JLabel("Enter the Range of password(16-32) ");
        l2.setFont(new Font("Arial", Font.CENTER_BASELINE, 15));
        t1=new JTextField(5);
        t1.setPreferredSize(new Dimension(300,20));
        l3=new JLabel("Generated password is ");
        l3.setFont(new Font("Arial", Font.BOLD, 12));
        t2=new JTextField(20);
        b1=new JButton("Generate");
        b2=new JButton("Reset");
        b1.setBounds(250, 150, 100, 100);
        b2.setBounds(300, 300, 100, 100);
        getContentPane().setBackground(Color.yellow);
        b1.setBackground(Color.GRAY);
        b2.setBackground(Color.GRAY);
        add(l1);
        add(l2);
        add(t1);
        add(l3);
        add(t2);
        add(b1);
        add(b2);
        b1.addActionListener(this);
        b2.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e){
        String uppercase="ABCDEFGHIKLMNOPQRSTUVWXYZ";
        String lowwercase="abcdefghijklnopqrstuvwxyz";
        String number="0123456789";
        String specialChar="!@#$%^&*()_{[}]-|:;'/?<,>.";
        String connection=uppercase+lowwercase+number+specialChar;
        String act=e.getActionCommand();
        if(act.equals("Generate")){
            String s=t1.getText();
            int n=Integer.parseInt(s);
            if(n<=15 || n>33){
                JOptionPane.showMessageDialog(password.this, "Enter a range between 16-32 .");
                t1.setText("\0");
                t2.setText("\0");
            }
            else{
                Random r=new Random();
                char []pass=new char[n];
                for(int i=0;i<n;i++){
                        pass[i]=connection.charAt(r.nextInt(connection.length()));
                }
                t2.setText(new String(pass));
            }
        }
        else{
            t1.setText("");
            t2.setText("");
        }
        
    }
    public static void main(String[] args) {
        password p=new password();
        p.setVisible(true);
        p.setBounds(100, 200, 400, 220);
        p.setTitle("Random_Password");
        p.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}