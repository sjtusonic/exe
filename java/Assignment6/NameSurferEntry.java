/*
 * File: NameSurferEntry.java
 * --------------------------
 * This class represents a single entry in the database.  Each
 * NameSurferEntry contains a name and a list giving the popularity
 * of that name for each decade stretching back to 1900.
 */

import acm.util.*;

import java.util.*;

public class NameSurferEntry implements NameSurferConstants {

/* Constructor: NameSurferEntry(line) */
/**
 * Creates a new NameSurferEntry from a data line as it appears
 * in the data file.  Each line begins with the name, which is
 * followed by integers giving the rank of that name for each
 * decade.
 */
	public NameSurferEntry(String line) {
		// You fill this in //
		StringTokenizer t=new StringTokenizer(line, " ");
		

		name=t.nextToken();
		while (t.hasMoreTokens()) {
			String u=t.nextToken();
//			System.out.println("NEXT RANK:"+u);
			this.rankList.add(u);
		}
//		System.out.println("name="+name);
//		System.out.println("rankList="+rankList);
	}

/* Method: getName() */
/**
 * Returns the name associated with this entry.
 */
	public String getName() {
		// You need to turn this stub into a real implementation //
		return this.name;
	}

/* Method: getRank(decade) */
/**
 * Returns the rank associated with an entry for a particular
 * decade.  The decade value is an integer indicating how many
 * decades have passed since the first year in the database,
 * which is given by the constant START_DECADE.  If a name does
 * not appear in a decade, the rank value is 0.
 */
	public int getRank(int decade) {
		// You need to turn this stub into a real implementation //
		Integer ind=decade/10-190;
		Integer rank= Integer.parseInt(this.rankList.get(ind));
		System.out.println("PROC getRank:"+decade+" =>"+rank);
		return rank;
	}

/* Method: toString() */
/**
 * Returns a string that makes it easy to see the value of a
 * NameSurferEntry.
 */
	public String toString() {
		// You need to turn this stub into a real implementation //

		return ("Name: [" + name + "] rankList: "
		+ rankList);
	}
	
	private ArrayList<String> rankList=new ArrayList<String>();
	private String name;
}

