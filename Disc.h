/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */
#ifndef REVERSI_DISC_H
#define REVERSI_DISC_H
 /**
  * A date struct representing coordinates.
  */
struct coordinates {
    int x;
    int y;
};

/**
 * A disc symbol type (for both players and discs objects).
 */
enum DiscSymbol {
    X = 'X',
    O = 'O',
    E = ' '
};

/**
 * This object represents a single disc on board.
 */
class Disc {
public:
/**
 * The default disc constructor.
 */
    Disc();

    /**
     * Disc object constructor.
     * @param sym the disc's symbol
     * @param x the disc's row index.
     * @param y the disc's column index.
     */
    explicit Disc(const DiscSymbol &sym, const int &x,const int &y) ;

    /**
     * Disc object constructor.
     * @param sym the disc's symbol.
     */
    explicit Disc(const DiscSymbol &sym);

    /**
     * @return the symbol of the disc
     */
    DiscSymbol  get_sym() const;

    /**
     * @return the disc's row location.
     */
    int         getloc_x() const;

    /**
     * @return the disc's column location.
     */
    int         getloc_y() const;

    /**
     * @param d checks if the coordinates of d match this objects coordinates.
     * @return true of false (if the coordinates match).
     */
    bool    check_coordinates(const Disc &d);
    /**
     * operator overloading for disc comparing.
     * @param d the Disc object we would like to compare.
     * @return if the Discs have to same coordinates.
     */
    bool operator ==(const Disc &d) const {
        return ((getloc_x() == d.getloc_x() && (getloc_y() == d.getloc_y())));
    }
private:
    DiscSymbol   symbol; // The disc's symbol.
    coordinates  coordinates_on_board; // The disc's coordinates.
};


#endif //REVERSI_DISC_H
