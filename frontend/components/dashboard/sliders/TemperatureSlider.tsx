import GenericSlider from './GenericSlider';

type Props = {

}

const TempuratureSlider = ({
}: Props) => {
  const marks = {
    20: '20°C',
    30: '30°C',
    40: '40°C',
  }
  return (  
    <GenericSlider
      title="Temperature"
      subtitle="In Celcius degree" 
      min={20} 
      max={40} 
      defaultValue={25} 
      marks={marks} 
      included={false}
      tipFormatter={(v) => (`${v}°C`)} />
  ) 
}

export default TempuratureSlider