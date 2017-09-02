/*
 * File: NameSurferGraph.java
 * ---------------------------
 * This class represents the canvas on which the graph of
 * names is drawn. This class is responsible for updating
 * (redrawing) the graphs whenever the list of entries changes
 * or the window is resized.
 */

import acm.graphics.*;

import java.awt.event.*;
import java.util.*;
import java.awt.*;

public class NameSurferGraph extends GCanvas
	implements NameSurferConstants, ComponentListener {

	/**
	* Creates a new NameSurferGraph object that displays the data.
	*/
	public NameSurferGraph() {
		addComponentListener(this);
		// You fill in the rest //		
		updateListOfDecades();
	}
	
	
	/**
	* Clears the list of name surfer entries stored inside this class.
	*/
	public void clear() {
		// You fill this in //
		Iterator<GObject> iterator=listOfGObject.iterator();
		while (iterator.hasNext()) {
			this.remove(iterator.next());
		}
		
	}
	
	
	/* Method: addEntry(entry) */
	/**
	* Adds a new NameSurferEntry to the list of entries on the display.
	* Note that this method does not actually draw the graph, but
	* simply stores the entry; the graph is drawn by calling update.
	*/
	public void addEntry(NameSurferEntry entry) {
		// You fill this in //
		this.listOfShowingEntry.add(entry);
		drawLinesForAnEntry(entry);
//		entry.getRank(decade) ;
		//TODO
	}
	
	
	/**
	* Updates the display image by deleting all the graphical objects
	* from the canvas and then reassembling the display according to
	* the list of entries. Your application must call update after
	* calling either clear or addEntry; update is also called whenever
	* the size of the canvas changes.
	*/
	public void update() {
		// You fill this in //
		this.clear();
//		ADD:
		double step_x=getWidth()/NDECADES;
//		GLine gl=new GLine(decade_y_grid, 0, decade_y_grid, box.getHeight());
//		System.out.println(decade_y_grid+" "+0+" "+decade_y_grid+" "+box.getHeight());
//		box.add(gl);
//		GLine gl1=new GLine(100 , 100,getWidth()	 ,getHeight());
//		System.out.println(-getWidth()+" "+-getHeight()+" "+getWidth() +" "+getHeight());
//		this.add(gl1);
		System.out.println("DONE");
//		double decade_x_grid=100;
//		GLine gl=new GLine(0, decade_x_grid, this.getWidth(),decade_x_grid);

		GLabel label =null;
		
		// update x,y loc arrays: 
		updateLoc_x();
		Iterator<NameSurferEntry> iteratorOfShowingEntry=listOfShowingEntry.iterator();
		while(iteratorOfShowingEntry.hasNext()) {
			NameSurferEntry nse=iteratorOfShowingEntry.next();
			updateLoc_y(nse);
			drawLinesForAnEntry(nse);
		}
		
		// redraw axes
		drawAxesWithDecadesLabel();
	}
	public void drawAxesWithDecadesLabel () {
		// draw Y axes and decade labels

		GLabel label =null;
		Iterator<Integer> iteratorOfDecades=listOfDecades.iterator() ;
		while(iteratorOfDecades.hasNext()){
			Integer currDecade=iteratorOfDecades.next();
			Double curr_x=match_decade2loc_x.get(currDecade);
			GLine tmp_gl=new GLine(curr_x , 0,curr_x , getHeight());
			listOfGObject.add(tmp_gl);
			System.out.println(curr_x+" "+-getHeight()+" "+curr_x+" "+getHeight());
			this.add(tmp_gl);	

			String name=String.valueOf(currDecade);
			label = new GLabel(name);
			listOfGObject.add(label);
			this.add(label, curr_x, getHeight());
		}
		
		// draw X axes:
		double curr_y=label.getAscent();
		GLine tmp_gl1=new GLine(  0,curr_y , getWidth(),curr_y);
		this.add(tmp_gl1);	
		listOfGObject.add(tmp_gl1);
		Y_BOTTOM=curr_y;
		curr_y=getHeight()-label.getAscent();
		GLine tmp_gl2=new GLine(  0,curr_y , getWidth(),curr_y);
		this.add(tmp_gl2);	
		listOfGObject.add(tmp_gl2);
		Y_TOP=curr_y;
	}
	
	public void drawLinesForAnEntry (NameSurferEntry nse) {
		updateLoc_y(nse);
		Iterator<Integer> iteratorOfDecades=listOfDecades.iterator() ;
		int cntr=0;
		Double oldx,oldy,x = null,y = null;
		while(iteratorOfDecades.hasNext()){
			Integer decade=iteratorOfDecades.next();
			oldx=x;
			oldy=y;
			x=match_decade2loc_x.get(decade);
			y=match_decade2loc_y.get(decade);
			
			// draw lines
			if(cntr>0) {
				GLine tmp_gl1=new GLine(  oldx,oldy ,x,y);
				this.add(tmp_gl1);	
				listOfGObject.add(tmp_gl1);
			}
			// draw labels
			Integer rank=nse.getRank(decade);
			String labelString;
			if (rank==0) {
				 labelString=nse.getName()+",*";
				
			} else {
				 labelString=nse.getName()+","+nse.getRank(decade);
			}
			GLabel temp_glabel1=new GLabel(labelString);

			this.add(temp_glabel1, x, y);
			listOfGObject.add(temp_glabel1);
			cntr++;
		}
		
	}
	public void updateListOfDecades () {
		for (Integer i=0;i<NDECADES;i++) {
			listOfDecades.add(START_DECADE+i*10);
		}
		System.out.println("PROC updateListOfDecades:"+listOfDecades);
	}
	public void updateLoc_x () {
		double step_x=getWidth()/NDECADES;
		double curr_x = 0;
		Iterator<Integer> iteratorOfDecades=listOfDecades.iterator() ;
		while(iteratorOfDecades.hasNext()){
			Integer i=iteratorOfDecades.next();
			match_decade2loc_x.put(i, curr_x);
			curr_x+=step_x;
		}
	}

	public void updateLoc_y (NameSurferEntry entry) {
		Iterator<Integer> iteratorOfDecades=listOfDecades.iterator() ;
		while(iteratorOfDecades.hasNext()){
			Integer decade=iteratorOfDecades.next();
			Integer rank=entry.getRank(decade);
			if (rank==0) {
				rank=MAX_RANK;
			}
			Double loc_y=Y_BOTTOM+(-(Y_BOTTOM-Y_TOP)/(1000))*rank;
			match_decade2loc_y.put(decade,loc_y);
			System.out.println("Y_TOP="+Y_TOP+"Y_BOTTOM="+Y_BOTTOM+"rank="+rank+"loc_y="+loc_y+"@DECADE"+decade);
			
		}
		
		
	
	}
	
	/* Implementation of the ComponentListener interface */
	public void componentHidden(ComponentEvent e) { }
	public void componentMoved(ComponentEvent e) { }
	public void componentResized(ComponentEvent e) { update(); }
	public void componentShown(ComponentEvent e) { }

	private ArrayList<GLine> u_Array_GLine=new ArrayList<GLine>();

	private ArrayList<GObject> listOfGObject=new ArrayList<GObject>();
	private ArrayList<Integer> listOfDecades=new ArrayList<Integer>();
//	private ArrayList<Double>  listOfXOfDecades=new ArrayList<Double>();
	private HashMap<Integer, Double> match_decade2loc_x=new HashMap<Integer, Double>();
	private HashMap<Integer, Double> match_decade2loc_y=new HashMap<Integer, Double>();
	private ArrayList<NameSurferEntry> listOfShowingEntry=new ArrayList<NameSurferEntry>();
	private Double Y_TOP;
	private Double Y_BOTTOM;
}
