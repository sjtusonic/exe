import java.util.*;
public class Album {
	/** Constructor
	* Note that the album name and year are immutable
	* once the album is created.
	*/
	public Album(String albumName, int year) {
	title = albumName;
	releaseYear = year;
	}
	public String getAlbumName() {
	return title;
	}
	public int getReleaseYear() {
	return releaseYear;
	}
	/** Adds a song to this album. There is no duplicate
	* checking for songs that are added.
	*/
	public void addSong(Song song) {
	songs.add(song);
	}
	/** Returns an iterator over all the songs that are
	* on this album.
	*/
	public Iterator<Song> getSongs() {
	return songs.iterator();
	}
	/** Returns a string representation of an album.
	*/
	public String toString() {
	return ("Album: [" + title + "] released in "
	+ releaseYear);
	}
	/* private instance variables */
	private String title;
	private int releaseYear;
	private ArrayList<Song> songs = new ArrayList<Song>();
}
