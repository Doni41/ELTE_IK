import hu.elte.hsfpoj.model.field.Field;
import org.junit.Assert;
import org.junit.Test;

public class FieldTest {

    @Test
    public void createNewField () {
        // GIVEN
        Field field = new Field(1, 2,3);

        // WHEN

        //THEM
        Assert.assertEquals(field.getPlayerID(), 1);
        Assert.assertEquals(field.getxCoord(), 2);
        Assert.assertEquals(field.getyCoord(), 3);
        Assert.assertFalse(field.isHasSpaceShip());
        Assert.assertFalse(field.isBlackHole());
        Assert.assertFalse(field.isSelected());
    }

    @Test
    public void createBlackHole () {
        // GIVEN
        Field field = new Field(0, 3,3);

        // WHEN
        field.setBlackHole(true);
        field.setSelected(true);

        // THEN

        Assert.assertFalse(field.isSelected());
        Assert.assertTrue(field.isBlackHole());
        Assert.assertFalse(field.isHasSpaceShip());
    }

    @Test
    public void selectField () {
        // GIVEN
        Field field = new Field(2, 4, 3);

        // WHEN
        field.setSelected(true);

        // THEN
        Assert.assertEquals(field.getPlayerID(), 2);
        Assert.assertEquals(field.getxCoord(), 4);
        Assert.assertEquals(field.getyCoord(), 3);
        Assert.assertTrue(field.isSelected());
    }

    @Test
    public void editField () {
        // GIVEN
        Field field = new Field(2, 2, 3);

        // WHEN
        field.setSelected(true);
        field.setHasSpaceShip(true);
        field.setPlayerID(1);

        // THEN
        Assert.assertEquals(field.getPlayerID(), 1);
        Assert.assertEquals(field.getxCoord(), 2);
        Assert.assertEquals(field.getyCoord(), 3);
        Assert.assertFalse(field.isBlackHole());
        Assert.assertTrue(field.isSelected());
        Assert.assertTrue(field.isHasSpaceShip());
    }
}
