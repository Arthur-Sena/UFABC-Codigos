/*
 *Conway's game of life was a cellular animation devised 
 *by the mathematician John Conway.
 *This Java, swing based implementation was created by Matthew Burke.
 *http://burke9077.com\nBurke9077@gmail.com\n@burke9077\n\nCreative 
 *Commons Attribution 4.0 International
*/

import java.awt.Dimension;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JSeparator;

import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import javax.swing.JOptionPane;

public class JogoDaVida extends JFrame implements ActionListener 
{
	private static final long serialVersionUID = -7599980162359810565L;
	//private static final Dimension DEFAULT_WINDOW_SIZE = new Dimension(800, 600);
    //private static final Dimension MINIMUM_WINDOW_SIZE = new Dimension(400, 400);
	private static final Dimension DEFAULT_WINDOW_SIZE = new Dimension(1680, 1050); 
    private static final Dimension MINIMUM_WINDOW_SIZE = new Dimension(800, 600);

    private JMenuBar menuBar;
    private JMenu menuArq, menuGol, menuAjuda;
    private JMenuItem menuVelocidade, menuSair;
    private JMenuItem menuAutoCompletar, menuExecutar, menuParar, menuReiniciar;
    private JMenuItem menuSobre;
    
    private static int iteracaoPorSegundo = 3;
    private TabuleiroGOL tabuleiroGol;
    private Thread threadGOL;
 
    public static void main(String[] args) 
    {
        JFrame gol = new JogoDaVida();
        /*
         * Definição das propriedades da janela do Jogo da Vida 
         */
        gol.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        gol.setTitle("Jogo da Vida de John Conway");
        gol.setSize(DEFAULT_WINDOW_SIZE);
        gol.setMinimumSize(MINIMUM_WINDOW_SIZE);
        gol.setLocation((Toolkit.getDefaultToolkit().getScreenSize().width - gol.getWidth())/2, 
                (Toolkit.getDefaultToolkit().getScreenSize().height - gol.getHeight())/2);
        gol.setVisible(true);
    }
 
    public JogoDaVida() 
    {   	
    	/**
    	 * Definição da barra de menu superior
    	 */
        menuBar = new JMenuBar();
        setJMenuBar(menuBar);
        menuArq = new JMenu("Arquivo");
        menuGol = new JMenu("Jogo Da Vida");
        menuAjuda = new JMenu("Ajuda");
        menuBar.add(menuArq);
        menuBar.add(menuGol);
        menuBar.add(menuAjuda);

        menuSair = new JMenuItem("Sair");
        menuSair.addActionListener(this);
        menuArq.add(menuSair);
        
        menuVelocidade = new JMenuItem("Velocidade");
        menuVelocidade.addActionListener(this);
        menuGol.add(menuVelocidade);
        menuGol.add(new JSeparator());        
        menuAutoCompletar = new JMenuItem("Auto-Preencher");
        menuAutoCompletar.addActionListener(this); 
        menuGol.add(menuAutoCompletar);
        menuGol.add(new JSeparator());              
        
        menuExecutar = new JMenuItem("Executar");
        menuExecutar.addActionListener(this);
        menuParar = new JMenuItem("Parar");
        menuParar.setEnabled(false);
        menuParar.addActionListener(this);
        menuReiniciar = new JMenuItem("Reiniciar");
        menuReiniciar.addActionListener(this);
        menuGol.add(menuExecutar);
        menuGol.add(menuParar);
        menuGol.add(menuReiniciar);
        
        menuSobre = new JMenuItem("Sobre");
        menuSobre.addActionListener(this);
        menuAjuda.add(menuSobre);
        
        tabuleiroGol = new TabuleiroGOL();
        add(tabuleiroGol);
    }
 
    public void definirRodarParar(boolean isBeingPlayed) 
    {
        if (isBeingPlayed) {
            menuExecutar.setEnabled(false);
            menuParar.setEnabled(true);
            threadGOL = new Thread(tabuleiroGol);
            threadGOL.start();
        } else {
            menuExecutar.setEnabled(true);
            menuParar.setEnabled(false);
            threadGOL.interrupt();
        }
    }
 
    public void actionPerformed(ActionEvent ae) 
    {
        if (ae.getSource().equals(menuSair)) 
        {
            // Sair do programa
            System.exit(0);
        } 
        else if (ae.getSource().equals(menuVelocidade)) 
        {
            // Put up an options panel to change the number of moves per second
            final JFrame confFrame = new JFrame();
            confFrame.setTitle("Velocidade");
            confFrame.setSize(500,100);
            confFrame.setLocation((Toolkit.getDefaultToolkit().getScreenSize().width - confFrame.getWidth())/2, 
                (Toolkit.getDefaultToolkit().getScreenSize().height - confFrame.getHeight())/2);
            confFrame.setResizable(false);
            
            JPanel textoVelocidade = new JPanel();
            textoVelocidade.setOpaque(false);
            confFrame.add(textoVelocidade);
    		JLabel label = new JLabel("Velocidade da simulação: Número de interações por segundo");
    		label.setFont(new Font("", Font.PLAIN, 16));
            textoVelocidade.add(label); 
            Object[] secondOptions = {"Selecione",1,2,4,5,10,15,20};
            final JComboBox cb_seconds = new JComboBox(secondOptions);
            textoVelocidade.add(cb_seconds);
            cb_seconds.setSelectedItem(iteracaoPorSegundo);
            
            cb_seconds.addActionListener(new ActionListener(){              
                public void actionPerformed(ActionEvent ae) 
                {
                    iteracaoPorSegundo = (Integer)cb_seconds.getSelectedItem();
                    setIteracaoPorSegundo(iteracaoPorSegundo);
                    confFrame.dispose();
                }
            });
            confFrame.setVisible(true);
        } 
        else if (ae.getSource().equals(menuAutoCompletar)) 
        {
            final JFrame f_autoFill = new JFrame();
            f_autoFill.setTitle("Auto-Preencher");
            f_autoFill.setSize(500, 100);
            f_autoFill.setLocation((Toolkit.getDefaultToolkit().getScreenSize().width - f_autoFill.getWidth())/2, 
                (Toolkit.getDefaultToolkit().getScreenSize().height - f_autoFill.getHeight())/2);
            f_autoFill.setResizable(false);
            JPanel p_autoFill = new JPanel();
            p_autoFill.setOpaque(false);
            f_autoFill.add(p_autoFill);
            
    		JLabel label = new JLabel("Com qual percentagem deseja preencher o tabuleiro?");
    		label.setFont(new Font("", Font.PLAIN, 16));          
            p_autoFill.add(label);
            Object[] percentagemOpcoes = {"Selecione",5,10,15,20,25,30,40,50,60,70,80,90,95};
            final JComboBox cb_percent = new JComboBox(percentagemOpcoes);
            p_autoFill.add(cb_percent);
            cb_percent.addActionListener(new ActionListener() {
                
                public void actionPerformed(ActionEvent e) {
                    if (cb_percent.getSelectedIndex() > 0) {
                        tabuleiroGol.resetBoard();
                        tabuleiroGol.preencherTabRandom((Integer)cb_percent.getSelectedItem());
                        f_autoFill.dispose();
                    }
                }
            });
            f_autoFill.setVisible(true);
        } 
        else if (ae.getSource().equals(menuReiniciar)) 
        {
            tabuleiroGol.resetBoard();
            tabuleiroGol.repaint();
        } 
        else if (ae.getSource().equals(menuExecutar)) 
        {
            definirRodarParar(true);
        } 
        else if (ae.getSource().equals(menuParar)) 
        {
            definirRodarParar(false);
        } 
        else if (ae.getSource().equals(menuSobre)) 
        {
            JOptionPane.showMessageDialog(null, "Conway's game of life was a cellular animation devised by the mathematician John Conway.\nThis Java, swing based implementation was created by Matthew Burke.\n\nhttp://burke9077.com\nBurke9077@gmail.com\n@burke9077\n\nCreative Commons Attribution 4.0 International");
        }
    }
    
    public static int getIteracaoPorSegundo() 
    {
		return iteracaoPorSegundo;
	}
    
    public void setIteracaoPorSegundo(int valor) 
    {
 		this.iteracaoPorSegundo = valor;
 	}
}