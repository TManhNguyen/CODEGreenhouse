import GenericSlider from './GenericSlider';

type Props = {

}

const DliSlider = ({
}: Props) => {
  const marks = {
    0: '0%',
    80: '80%',
    100: '100%',
  }
  return (  
    <GenericSlider
      title="DLI"
      subtitle="Daily light integral"
      min={0} 
      max={100} 
      defaultValue={90} 
      marks={marks} 
      included={false}
      tipFormatter={(v) => (`${v}%`)} />
  ) 
}

export default DliSlider