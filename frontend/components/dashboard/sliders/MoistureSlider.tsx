import GenericSlider from './GenericSlider';

type Props = {

}

const MoistureSlider = ({
}: Props) => {
  const marks = {
    0: '0%',
    50: '50%',
    100: '100%',
  }
  return (  
    <GenericSlider
      title="Humidity"
      subtitle="Air water vapor concentration" 
      min={0} 
      max={100} 
      defaultValue={70} 
      marks={marks} 
      included={false}
      tipFormatter={(v) => (`${v}%`)} />
  ) 
}

export default MoistureSlider