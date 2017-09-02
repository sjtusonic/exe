/*
 * File: NameSurferDataBase.java
 * -----------------------------
 * This class keeps track of the complete database of names.
 * The constructor reads in the database from a file, and
 * the only public method makes it possible to look up a
 * name and get back the corresponding NameSurferEntry.
 * Names are matched independent of case, so that "Eric"
 * and "ERIC" are the same names.
 */

import acm.util.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

import sun.security.action.OpenFileInputStreamAction;

public class NameSurferDataBase implements NameSurferConstants {
	
/* Constructor: NameSurferDataBase(filename) */
/**
 * Creates a new NameSurferDataBase and initializes it using the
 * data in the specified file.  The constructor throws an error
 * exception if the requested file does not exist or if an error
 * occurs as the file is being read.
 */
		BufferedReader rd=null;
//		ArrayList<NameSurferEntry> lineList;
		HashMap<String, NameSurferEntry> match_String2NameSurferEntry;
		NameSurferEntry u_NameSurferEntry;
	public NameSurferDataBase(String filename) {
		// You fill this in //
		try {
			rd=new BufferedReader(new FileReader(filename));
			match_String2NameSurferEntry=new HashMap<String, NameSurferEntry>();
			while (true) {
				String line=rd.readLine();
				if (line==null) break;
				System.out.println("GET LINE:"+line);
				u_NameSurferEntry =new NameSurferEntry(line);
				
				String name=u_NameSurferEntry.getName();
				System.out.println("GET NAME:"+name);
				
				if (!match_String2NameSurferEntry.containsKey(name)) {
					match_String2NameSurferEntry.put(name, u_NameSurferEntry);
					System.out.println("succeed in reading "+name);
				} else {
					System.out.println(name+" is already existing, plz check the file "+filename);	
				}
			}
		} catch (IOException ex) {
			System.out.println ("Can't open that file:"+filename);
		}
	}

/* Method: findEntry(name) */
/**
 * Returns the NameSurferEntry associated with this name, if one
 * exists.  If the name does not appear in the database, this
 * method returns null.
 */
	public NameSurferEntry findEntry(String name) {
		// You need to turn this stub into a real implementation //
		if (match_String2NameSurferEntry.containsKey(name)) {
			return match_String2NameSurferEntry.get(name);
		} else {
			NameSurferEntry nse=new NameSurferEntry("NA 0 0 0 0 0 0 0 0 0 0 0");
			return nse;
		}
	}
}

